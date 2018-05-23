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

static void report(const char *prefix, const char *err, va_list params) {
        fputs(prefix, stderr);
        vfprintf(stderr, err, params);
        fputs("\n", stderr);
}

void usage(const char *err) {
        fprintf(stderr, "usage: %s\n", err);

        exit(1);
}

void die(const char *err, ...) {
        va_list params;

        va_start(params, err);
        report("fatal: ", err, params);
        va_end(params);

        exit(1);
}

int error(const char *err, ...) {
        va_list params;

        va_start(params, err);
        report("error: ", err, params);
        va_end(params);

	return -1;
}

