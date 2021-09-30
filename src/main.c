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

#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "uci.h"
#include "config.h"


int main(int argc, char **argv) {

  //clear the screen before printing out
  system("clear");

  //get the number of cores on the current platform
  //if there is more than one, could consider some parallelism on tasks
  getNbCores();

  all_init();

  uci();

  return 0;
}
