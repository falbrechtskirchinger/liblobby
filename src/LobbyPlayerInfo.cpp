// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-2.0-or-later

#include "liblobby/LobbyPlayerInfo.h"

#include <libutil/Serializer.h>

LobbyPlayerInfo::LobbyPlayerInfo()
{
    clear();
}

LobbyPlayerInfo::LobbyPlayerInfo(const unsigned /*playerId*/, Serializer& ser)
{
    deserialize(ser);
    isIngame = false;
}

/**
 *  leert die Informationen.
 */
void LobbyPlayerInfo::clear()
{
    playerId_ = 0;
    name_.clear();
    version_.clear();
    punkte_ = 0;
    gewonnen_ = 0;
    verloren_ = 0;
    isIngame = false;
}

/**
 *  serialisiert die Daten.
 *
 *  @param[in] ser der benutzte Serializer
 */
void LobbyPlayerInfo::serialize(Serializer& ser) const
{
    ser.PushUnsignedInt(playerId_);
    ser.PushLongString(name_);
    ser.PushLongString(version_);
    ser.PushSignedInt(punkte_);
    ser.PushUnsignedInt(gewonnen_);
    ser.PushUnsignedInt(verloren_);
}

/**
 *  deserialisiert die Daten.
 *
 *  @param[in] ser der benutzte Serializer
 */
void LobbyPlayerInfo::deserialize(Serializer& ser)
{
    playerId_ = ser.PopUnsignedInt();
    name_ = ser.PopLongString();
    version_ = ser.PopLongString();
    punkte_ = ser.PopSignedInt();
    gewonnen_ = ser.PopUnsignedInt();
    verloren_ = ser.PopUnsignedInt();
}
