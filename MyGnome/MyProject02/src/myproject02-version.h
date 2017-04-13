/* myproject02-version.h.in
 *
 * Copyright (C) 2017 mhcrnl
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MYPROJECT02_VERSION_H
#define MYPROJECT02_VERSION_H

#if !defined(MYPROJECT02_INSIDE) && !defined(MYPROJECT02_COMPILATION)
# error "Only <myproject02.h> can be included directly."
#endif

/**
 * SECTION:myproject02version
 * @short_description: myproject02 version checking
 *
 * myproject02 provides macros to check the version of the library
 * at compile-time
 */

/**
 * MYPROJECT02_MAJOR_VERSION:
 *
 * myproject02 major version component (e.g. 1 if %MYPROJECT02_VERSION is 1.2.3)
 */
#define MYPROJECT02_MAJOR_VERSION (0)

/**
 * MYPROJECT02_MINOR_VERSION:
 *
 * myproject02 minor version component (e.g. 2 if %MYPROJECT02_VERSION is 1.2.3)
 */
#define MYPROJECT02_MINOR_VERSION (1)

/**
 * MYPROJECT02_MICRO_VERSION:
 *
 * myproject02 micro version component (e.g. 3 if %MYPROJECT02_VERSION is 1.2.3)
 */
#define MYPROJECT02_MICRO_VERSION (0)

/**
 * MYPROJECT02_VERSION
 *
 * myproject02 version.
 */
#define MYPROJECT02_VERSION (0.1.0)

/**
 * MYPROJECT02_VERSION_S:
 *
 * myproject02 version, encoded as a string, useful for printing and
 * concatenation.
 */
#define MYPROJECT02_VERSION_S "0.1.0"

#define MYPROJECT02_ENCODE_VERSION(major,minor,micro) \
        ((major) << 24 | (minor) << 16 | (micro) << 8)

/**
 * MYPROJECT02_VERSION_HEX:
 *
 * myproject02 version, encoded as an hexadecimal number, useful for
 * integer comparisons.
 */
#define MYPROJECT02_VERSION_HEX \
        (MYPROJECT02_ENCODE_VERSION (MYPROJECT02_MAJOR_VERSION, MYPROJECT02_MINOR_VERSION, MYPROJECT02_MICRO_VERSION))

/**
 * MYPROJECT02_CHECK_VERSION:
 * @major: required major version
 * @minor: required minor version
 * @micro: required micro version
 *
 * Compile-time version checking. Evaluates to %TRUE if the version
 * of myproject02 is greater than the required one.
 */
#define MYPROJECT02_CHECK_VERSION(major,minor,micro)   \
        (MYPROJECT02_MAJOR_VERSION > (major) || \
         (MYPROJECT02_MAJOR_VERSION == (major) && MYPROJECT02_MINOR_VERSION > (minor)) || \
         (MYPROJECT02_MAJOR_VERSION == (major) && MYPROJECT02_MINOR_VERSION == (minor) && \
          MYPROJECT02_MICRO_VERSION >= (micro)))

#endif /* MYPROJECT02_VERSION_H */
