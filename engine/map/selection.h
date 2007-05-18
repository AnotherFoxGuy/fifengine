/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_MAP_SELECTION_H
#define FIFE_MAP_SELECTION_H

// Standard C++ library includes

// 3rd party library includes
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "util/point.h"

namespace FIFE { 

	class Screen;

	namespace map {

	class Layer;
	typedef boost::shared_ptr<Layer> LayerPtr;
	typedef boost::weak_ptr<Layer> LayerWeakPtr;

	class Selection {

		public:
			enum Mode {
				SingleSelectionMode,
				MultiSelectionMode
			};

			Selection(LayerWeakPtr layer);
			Selection(const Selection& selection);

			~Selection();

			void setImage(size_t imageid);

			void setMode(Mode mode);
			Mode getMode() const;

			void select(const Point& p);
			void unselect(const Point& p);
			bool isSelected(const Point& p) const;
			void clearSelection();

			void render(Screen* screen, const Point& offset);

		private:
			Mode m_mode;
			size_t m_imageid;
			LayerWeakPtr m_layer;

			bool m_selected;
			Point m_selection;
			std::vector<Point> m_multiselection;

			void initImageFromLayer();
	};

} } //FIFE::map

#endif
