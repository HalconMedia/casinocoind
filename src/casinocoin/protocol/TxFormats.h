//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

//==============================================================================
/*
    2017-06-30  ajochems        Refactored for casinocoin
*/
//==============================================================================

#ifndef CASINOCOIN_PROTOCOL_TXFORMATS_H_INCLUDED
#define CASINOCOIN_PROTOCOL_TXFORMATS_H_INCLUDED

#include <casinocoin/protocol/KnownFormats.h>

namespace casinocoin {

/** Transaction type identifiers.

    These are part of the binary message format.

    @ingroup protocol
*/
enum TxType
{
    ttINVALID           = -1,

    ttPAYMENT           = 0,
    ttESCROW_CREATE     = 1,
    ttESCROW_FINISH     = 2,
    ttACCOUNT_SET       = 3,
    ttESCROW_CANCEL     = 4,
    ttREGULAR_KEY_SET   = 5,
    ttNICKNAME_SET      = 6, // open
    ttOFFER_CREATE      = 7,
    ttOFFER_CANCEL      = 8,
    no_longer_used      = 9,
    ttTICKET_CREATE     = 10,
    ttTICKET_CANCEL     = 11,
    ttSIGNER_LIST_SET   = 12,
    ttPAYCHAN_CREATE    = 13,
    ttPAYCHAN_FUND      = 14,
    ttPAYCHAN_CLAIM     = 15,

    ttTRUST_SET         = 20,

    ttKYC_SET           = 30,

    ttAMENDMENT         = 100,
    ttFEE               = 101,
    ttCONFIG            = 102
};

/** Manages the list of known transaction formats.
*/
class TxFormats : public KnownFormats <TxType>
{
private:
    void addCommonFields (Item& item);

public:
    /** Create the object.
        This will load the object will all the known transaction formats.
    */
    TxFormats ();

    static TxFormats const& getInstance ();
};

} // casinocoin

#endif
