/* contentdisposition.cpp
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

#include <tnt/contentdisposition.h>
#include <ctype.h>
#include <functional>
#include <algorithm>

namespace tnt
{
  Contentdisposition::return_type Contentdisposition::onType(
    const std::string& t,
    const std::string& subtype)
  {
    if (!subtype.empty())
      return FAIL;

    type = t;
    std::transform(type.begin(), type.end(), type.begin(),
      std::ptr_fun(tolower));

    return OK;
  }

  Contentdisposition::return_type Contentdisposition::onParameter(
    const std::string& attribute,
    const std::string& value)
  {
    if (attribute == "name")
    {
      name = value;
      //std::transform(name.begin(), name.end(), name.begin(),
        //std::ptr_fun(tolower));
    }
    else if (attribute == "filename")
      filename = value;

    return OK;
  }
}
