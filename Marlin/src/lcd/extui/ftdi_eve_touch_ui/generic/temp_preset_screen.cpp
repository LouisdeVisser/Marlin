/********************
 * temp_preset_screen.cpp *
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

#ifdef FTDI_TEMPERATURE_PRESET_SCREEN

using namespace FTDI;
using namespace ExtUI;
using namespace Theme;


void TemperaturePresetScreen::onRedraw(draw_mode_t what) {
  widgets_t w(what);
  w.precision(0, DEFAULT_MIDRANGE);
  w.units(GET_TEXT_F(MSG_UNITS_C));
  w.heading(                        GET_TEXT_F(MSG_STEPS_PER_MM));
  w.color(temp)    	.adjuster( 2, 	GET_TEXT_F(MSG_T_PRESET1_END),  getPresetEndTemp1() );
  w.color(temp)     .adjuster( 4, 	GET_TEXT_F(MSG_T_PRESET1_BED),  getPresetBedTemp1() );
  w.color(temp)     .adjuster( 6, 	GET_TEXT_F(MSG_T_PRESET2_END),  getPresetEndTemp2() );
	w.color(temp)     .adjuster( 8, 	GET_TEXT_F(MSG_T_PRESET2_BED),  getPresetBedTemp2() );
	w.color(temp)			.button(	 10, 	GET_TEXT_F(MSG_MPC_START));
  w.increments();
}

bool TemperaturePresetScreen::onTouchHeld(uint8_t tag) {
  const float increment = getIncrement();
  switch (tag) {
    case  2: UI_DECREMENT(PresetEndTemp1);  break;
    case  3: UI_INCREMENT(PresetEndTemp1);  break;
    case  4: UI_DECREMENT(PresetBedTemp1);  break;
    case  5: UI_INCREMENT(PresetBedTemp1);  break;
    case  6: UI_DECREMENT(PresetEndTemp2);  break;
    case  7: UI_INCREMENT(PresetEndTemp2);  break;
    case  8: UI_DECREMENT(PresetBedTemp2);  break;
    case  9: UI_INCREMENT(PresetBedTemp2);  break;
		case 	10: injectCommands(F("M306 T")); break;
    default:
      return false;
  }
  SaveSettingsDialogBox::settingsChanged();
  return true;
}

#endif // FTDI_STEPS_SCREEN
