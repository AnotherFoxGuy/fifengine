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

#ifndef FIFE_COORDINATERENDERER_H
 #define FIFE_COORDINATERENDERER_H

// Standard C++ library includes

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "view/rendererbase.h"
#include "util/rect.h"

namespace FIFE {
	class RenderBackend;
	class ImagePool;

	class CoordinateRenderer: public RendererBase {
	public:
		/** constructor.
		 * @param renderbackend to use
		 * @param imagepool image pool where from fetch images
		 */
		CoordinateRenderer(RenderBackend* renderbackend, ImagePool* imagepool);
		
		/** Destructor.
		 */
		virtual ~CoordinateRenderer();
		
		void render(Camera* cam, Layer* layer, std::vector<Instance*>& instances, int stackpos);
		
		std::string getName() { return "CoordinateRenderer"; }

	private:
		void adjustLayerArea();
	
		RenderBackend* m_renderbackend;
		ImagePool* m_imagepool;
		Rect m_layer_area;
		Location m_tmploc;
		ExactModelCoordinate m_c;
	};

}

#endif