/*
  Xiphos, a UCI chess engine
  Copyright (C) 2018, 2019 Milos Tatarevic

  (With additions from Marc-Philippe Huget)

  Xiphos is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Xiphos is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "make.h"
#include "pawn_eval.h"
#include "search.h"
#include "tables.h"

/* 
    This function was initially in the main function but an init module seems to be better
*/
void all_init() {

    //make.c
    init_rook_c_flag_mask();

    //bitboard.c
    init_bitboards();

    //pawn_eval.c
    init_distance();
  
    //tables.c
    init_pst();
  
    //search.c
    init_lmr();

}