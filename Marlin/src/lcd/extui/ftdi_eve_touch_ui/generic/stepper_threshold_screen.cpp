/******************************
 * stepper_current_screen.cpp *
 ******************************/

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

#ifdef FTDI_STEPPER_THRESHOLD_SCREEN

using namespace FTDI;
using namespace ExtUI;
using namespace Theme;

void StepperThresholdScreen::onRedraw(draw_mode_t what) {
  widgets_t w(what);
  w.precision(0);
  w.units(GET_TEXT_F(MSG_UNITS_MM_S));
  w.heading(GET_TEXT_F(MSG_TMC_HYBRID_THRS));
  TERN_(X_IS_TRINAMIC,  w.color(x_axis) .adjuster( 2, GET_TEXT_F(MSG_AXIS_X),  getTMCThresholdCurrent(X) ) );
  TERN_(X2_IS_TRINAMIC, w.color(x_axis) .adjuster( 4, GET_TEXT_F(MSG_AXIS_X2), getTMCThresholdCurrent(X2)) );
  TERN_(Y_IS_TRINAMIC,  w.color(y_axis) .adjuster( 6, GET_TEXT_F(MSG_AXIS_Y),  getTMCThresholdCurrent(Y) ) );
  TERN_(Y2_IS_TRINAMIC, w.color(x_axis) .adjuster( 8, GET_TEXT_F(MSG_AXIS_Y2), getTMCThresholdCurrent(Y2)) );
  TERN_(Z_IS_TRINAMIC,  w.color(z_axis) .adjuster(10, GET_TEXT_F(MSG_AXIS_Z),  getTMCThresholdCurrent(Z) ) );
  TERN_(Z2_IS_TRINAMIC, w.color(z_axis) .adjuster(12, GET_TEXT_F(MSG_AXIS_Z2), getTMCThresholdCurrent(Z2)) );
	TERN_(Z3_IS_TRINAMIC, w.color(z_axis) .adjuster(14, GET_TEXT_F(MSG_AXIS_Z3), getTMCThresholdCurrent(Z3)) );
  TERN_(E0_IS_TRINAMIC, w.color(e_axis) .adjuster(16, GET_TEXT_F(TERN(HAS_MULTI_EXTRUDER, MSG_AXIS_E1, MSG_AXIS_E)), getTMCThresholdCurrent(E0)) );
  TERN_(E1_IS_TRINAMIC, w.color(e_axis) .adjuster(18, GET_TEXT_F(MSG_AXIS_E2), getTMCThresholdCurrent(E1)) );
  TERN_(E2_IS_TRINAMIC, w.color(e_axis) .adjuster(20, GET_TEXT_F(MSG_AXIS_E3), getTMCThresholdCurrent(E2)) );
  TERN_(E3_IS_TRINAMIC, w.color(e_axis) .adjuster(22, GET_TEXT_F(MSG_AXIS_E4), getTMCThresholdCurrent(E3)) );
  w.increments();
}

bool StepperThresholdScreen::onTouchHeld(uint8_t tag) {
  const float increment = getIncrement();
  switch (tag) {
    #if X_IS_TRINAMIC
      case  2: UI_DECREMENT(TMCThresholdCurrent, X ); break;
      case  3: UI_INCREMENT(TMCThresholdCurrent, X ); break;
    #endif
    #if X2_IS_TRINAMIC
      case  4: UI_DECREMENT(TMCThresholdCurrent, X2 ); break;
      case  5: UI_INCREMENT(TMCThresholdCurrent, X2 ); break;
    #endif
    #if Y_IS_TRINAMIC
      case  6: UI_DECREMENT(TMCThresholdCurrent, Y ); break;
      case  7: UI_INCREMENT(TMCThresholdCurrent, Y ); break;
    #endif
    #if Y2_IS_TRINAMIC
      case  8: UI_DECREMENT(TMCThresholdCurrent, Y2 ); break;
      case  9: UI_INCREMENT(TMCThresholdCurrent, Y2 ); break;
    #endif
    #if Z_IS_TRINAMIC
      case 10: UI_DECREMENT(TMCThresholdCurrent, Z ); break;
      case 11: UI_INCREMENT(TMCThresholdCurrent, Z ); break;
    #endif
    #if Z2_IS_TRINAMIC
      case 12: UI_DECREMENT(TMCThresholdCurrent, Z2 ); break;
      case 13: UI_INCREMENT(TMCThresholdCurrent, Z2 ); break;
    #endif
    #if Z3_IS_TRINAMIC
      case 14: UI_DECREMENT(TMCThresholdCurrent, Z3 ); break;
      case 15: UI_INCREMENT(TMCThresholdCurrent, Z3 ); break;
    #endif
    #if E0_IS_TRINAMIC
      case 16: UI_DECREMENT(TMCThresholdCurrent, E0); break;
      case 17: UI_INCREMENT(TMCThresholdCurrent, E0); break;
    #endif
    #if E1_IS_TRINAMIC
      case 18: UI_DECREMENT(TMCThresholdCurrent, E1); break;
      case 19: UI_INCREMENT(TMCThresholdCurrent, E1); break;
    #endif
    #if E2_IS_TRINAMIC
      case 20: UI_DECREMENT(TMCThresholdCurrent, E2); break;
      case 21: UI_INCREMENT(TMCThresholdCurrent, E2); break;
    #endif
    #if E3_IS_TRINAMIC
      case 22: UI_DECREMENT(TMCThresholdCurrent, E3); break;
      case 23: UI_INCREMENT(TMCThresholdCurrent, E3); break;
    #endif
    default:
      return false;
  }
  SaveSettingsDialogBox::settingsChanged();
  return true;
}

#endif // FTDI_STEPPER_THRESHOLD_SCREEN
