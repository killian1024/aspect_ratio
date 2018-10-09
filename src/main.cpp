/* aspect_ratio
 * Copyright (C) 2018 Killian Poulaud.
 *
 * This file is part of aspect_ratio.
 *
 * aspect_ratio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * aspect_ratio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with speed. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <iostream>

#include <speed/speed.hpp>
#include <speed/speed_alias.hpp>


int main(int argc, char* argv[])
{
    spd::ap::arg_parser ap("aspect_ratio");
    ap.add_help_text("Options:");
    ap.add_help_arg({"--help"}, "Display this help and exit.");
    ap.add_gplv3_version_arg({"--version"}, "Output version information and exit",
                             "1.0.0", "2018", "Killian Poulaud");
    ap.add_keyless_arg("TARGET-WIDTH", "TARGET-WIDTH", "Specify the target width",
                       {spd::ap::avt_t::UINT64}, 1, 1);
    ap.add_keyless_arg("TARGET-HEIGHT", "TARGET-HEIGHT", "Specify the target height",
                       {spd::ap::avt_t::UINT64}, 1, 1);
    ap.add_keyless_arg("SOURCE-WIDTH", "SOURCE-WIDTH", "Specify the source width",
                       {spd::ap::avt_t::UINT64}, 1, 1);
    ap.add_keyless_arg("SOURCE-HEIGHT", "SOURCE-HEIGHT", "Specify the source height",
                       {spd::ap::avt_t::UINT64}, 1, 1);
    ap.parse_args((unsigned int)argc, argv);
    
    auto trg_wgth = ap.get_front_arg_value_as<std::uint64_t>("TARGET-WIDTH");
    auto trg_hght = ap.get_front_arg_value_as<std::uint64_t>("TARGET-HEIGHT");
    auto src_wgth = ap.get_front_arg_value_as<std::uint64_t>("SOURCE-WIDTH");
    auto src_hght = ap.get_front_arg_value_as<std::uint64_t>("SOURCE-HEIGHT");
    
    std::cout << "Result keeping width  : "
              << src_wgth << " × " << (src_wgth * trg_hght) / (double)trg_wgth
              << spd::ios::newl
              << "Result keeping height : "
              << (trg_wgth * src_hght) / (double)trg_hght << " × " << src_hght
              << spd::ios::newl;
    
    return 0;
}
