/* 
 * Copyright (C) 2018 Jack Green (ja-green)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * hash-string:
 *
 * Hashes a single string using the hash function specified
 * by the user using the '-m' switch and prints the result
 * to stdout. If the '-m' switch is not specified it
 * returns the input string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "usage.c"

static const char *hash_string_usage =
    "athena-hash-string [-m <mode>] [string...]";

static struct option long_options[] = {
    {"mode", 	required_argument, 	NULL, 	'm' },
    {NULL,	0, 			NULL, 	0 }
};

int get_hash(unsigned int mode) {
    return mode;
}

int main(int argc, char **argv) {
    unsigned int opt	= 0;
    unsigned int mode	= 0;

    while ((opt = getopt_long(argc, argv, ":m:", long_options, NULL)) != -1) {
        switch (opt) {
        case 'm': 	mode = atoi(optarg);		break;

        default: 	usage(hash_string_usage);	break;

        }   
    }
    
    printf("mode is %d\n", get_hash(mode));
}

