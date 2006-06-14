/* zdata.cpp
 * Copyright (C) 2003 Tommi Maekitalo
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

#include <tnt/zdata.h>
#include <zlib.h>
#include <stdexcept>
#include <cxxtools/thread.h>
#include <cxxtools/log.h>

log_define("tntnet.data")

namespace tnt
{
  static cxxtools::Mutex mutex;

  void Zdata::addRef()
  {
    cxxtools::MutexLock lock(mutex);
    if (refs++ == 0)
    {
      // allocate uncompressed data
      data = new char[data_len];

      // uncompress Zdata => data
      log_debug("uncompress " << zdata_len << " to " << data_len << " bytes");
      uLong dest_len = data_len;
      int z_ret = uncompress((Bytef*)data, &dest_len, (const Bytef*)zptr, zdata_len);
      if (z_ret != Z_OK)
      {
        throw std::runtime_error(std::string("error uncompressing data: ") +
          (z_ret == Z_MEM_ERROR ? "Z_MEM_ERROR" :
           z_ret == Z_BUF_ERROR ? "Z_BUF_ERROR" :
           z_ret == Z_DATA_ERROR ? "Z_DATA_ERROR" : "unknown error"));
      }
      log_debug("uncompress ready");
    }
  }

  void Zdata::release()
  {
    cxxtools::MutexLock lock(mutex);
    if (--refs <= 0)
    {
      log_debug("release " << data_len << " uncompressed bytes");
      delete[] data;
      data = 0;
    }
  }

}
