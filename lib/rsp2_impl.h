/* -*- c++ -*- */
/*
 * Copyright 2020 Franco Venturi.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_SDRPLAY3_RSP2_IMPL_H
#define INCLUDED_SDRPLAY3_RSP2_IMPL_H

#include "rsp_impl.h"
#include <gnuradio/sdrplay3/rsp2.h>

namespace gr {
namespace sdrplay3 {

class rsp2_impl : public rsp2, public rsp_impl
{
public:
    rsp2_impl(const std::string& selector,
              const struct stream_args_t& stream_args);
    ~rsp2_impl();

    // Antenna methods
    const std::string set_antenna(const std::string& antenna) override;
    const std::string get_antenna() const override;
    const std::vector<std::string> get_antennas() const override;

    // Miscellaneous stuff
    void set_rf_notch_filter(bool enable) override;
    void set_biasT(bool enable) override;

private:

    static const std::vector<int> rf_gr_values(const double freq, const bool hdr_mode);
    const std::vector<int> rf_gr_values() const override;

    void print_device_config() const override;
};

} // namespace sdrplay3
} // namespace gr

#endif /* INCLUDED_SDRPLAY3_RSP2_IMPL_H */
