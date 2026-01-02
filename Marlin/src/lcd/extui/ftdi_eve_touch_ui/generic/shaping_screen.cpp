/********************
 * shaping_screen.cpp *
 ********************/

/****************************************************************************
 *   Written By Mark Pelletier  2017 - Aleph Objects, Inc.                  *
 *   Written By Marcio Teixeira 2018 - Aleph Objects, Inc.                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <https://www.gnu.org/licenses/>.                             *
 ****************************************************************************/

#include "../config.h"
#include "../screens.h"

#ifdef FTDI_SHAPING_SCREEN

using namespace FTDI;
using namespace ExtUI;
using namespace Theme;

void ShapingScreen::onRedraw(draw_mode_t what) {
  widgets_t w(what);
  w.precision(2, DEFAULT_LOWEST);
  w.heading(            GET_TEXT_F(MSG_SHAPING_MENU));
	w.toggle( 2,					GET_TEXT_F(MSG_ENABLE_SHAPING), 																						  getShapingState()  );
  w.color(x_axis).units(GET_TEXT_F(MSG_UNIT_FREQ)).adjuster( 4, 		GET_TEXT_F(MSG_SHAPING_A_FREQ),   getShapingFrequency(X) );
	w.color(y_axis).units(GET_TEXT_F(MSG_UNIT_FREQ)).adjuster( 6, 		GET_TEXT_F(MSG_SHAPING_B_FREQ),   getShapingFrequency(Y) );
  w.color(x_axis).units(GET_TEXT_F(MSG_UNIT_ZETA)).adjuster( 8, 		GET_TEXT_F(MSG_DAMPING_A_RATIO),  getShapingZeta(X) );
	w.color(y_axis).units(GET_TEXT_F(MSG_UNIT_ZETA)).adjuster( 10, 		GET_TEXT_F(MSG_DAMPING_B_RATIO),  getShapingZeta(Y) );
  w.increments();
}


bool ShapingScreen::onTouchHeld(uint8_t tag) {
  const float increment = getIncrement();
  switch (tag) {
		case 	2: setShapingState(!getShapingState()); break;
    case  4: UI_DECREMENT(ShapingFrequency, X); break;
		case	5: UI_INCREMENT(ShapingFrequency, X); break;
    case  6: UI_DECREMENT(ShapingFrequency, Y); break;
		case	7: UI_INCREMENT(ShapingFrequency, Y); break;
    case  8: UI_DECREMENT(ShapingZeta, X); break;
    case  9: UI_INCREMENT(ShapingZeta, X); break;
		case 	10: UI_DECREMENT(ShapingZeta, Y);  break;
		case	11: UI_INCREMENT(ShapingZeta, Y);  break;
    default: return false;
  }
  SaveSettingsDialogBox::settingsChanged();
  return true;
}

#endif // FTDI_SHAPING_SCREEN
