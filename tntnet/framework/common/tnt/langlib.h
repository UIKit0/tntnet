/* tnt/langlib.h
 * Copyright (C) 2006 Tommi Maekitalo
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

#ifndef TNT_LANGLIB_H
#define TNT_LANGLIB_H

#include <string>
#include <map>
#include <set>
#include <tnt/unzipfile.h>
#include <cxxtools/thread.h>

namespace tnt
{
  class LangLib
  {
      unzipFile file;
      std::string lang;
      typedef std::map<std::string, std::string> dataMapType;
      typedef std::set<std::string> notFoundType;
      dataMapType dataMap;
      notFoundType notFound;
      cxxtools::RWLock monitor;

    public:
      LangLib()
        { }

      LangLib(const std::string lib, const std::string& lang_);

      const char* getData(const std::string& compname);
  };
}

#endif // TNT_LANGLIB_H

