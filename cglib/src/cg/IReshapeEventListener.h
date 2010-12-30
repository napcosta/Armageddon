// This file is part of CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho

#ifndef IRESHAPE_EVENT_LISTENER_H
#define IRESHAPE_EVENT_LISTENER_H

namespace cg {

	/** cg::IReshapeEventListener is the callback interface for reshape events.
	 */
	class IReshapeEventListener {
    public:
        virtual void onReshape(int width, int height) = 0;

        virtual ~IReshapeEventListener(){}
    };

}

#endif // IRESHAPE_EVENT_LISTENER_H
