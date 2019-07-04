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

#pragma once
#ifndef liblobby_include_liblobby_LobbyServerInfo_h
#define liblobby_include_liblobby_LobbyServerInfo_h

#include <string>

class Serializer;

class LobbyServerInfo
{
public:
    LobbyServerInfo();
    LobbyServerInfo(unsigned playerId, Serializer& ser);
    /// leert die Informationen.
    void clear();
    /// serialisiert die Daten.
    void serialize(Serializer& ser) const;

    unsigned getId() const { return serverid; }
    std::string getName() const { return name; }
    std::string getHost() const { return host; }
    unsigned short getPort() const { return port; }
    std::string getVersion() const { return version; }
    unsigned getPing() const { return ping; }
    std::string getMap() const { return map; }
    unsigned getCurPlayers() const { return curplayers; }
    unsigned getMaxPlayers() const { return maxplayers; }
    bool hasPassword() const { return has_password; }

    void setId(const unsigned serverid) { this->serverid = serverid; }
    void setName(const std::string& name) { this->name = name; }
    void setHost(const std::string& host) { this->host = host; }
    void setPort(const unsigned short port) { this->port = port; }
    void setVersion(const std::string& version) { this->version = version; }
    void setPing(const unsigned short ping) { this->ping = ping; }
    void setMap(const std::string& map) { this->map = map; }
    void setCurPlayers(const unsigned curplayers) { this->curplayers = curplayers; }
    void setMaxPlayers(const unsigned maxplayers) { this->maxplayers = maxplayers; }
    void setPassword(bool has_password) { this->has_password = has_password; }

private:
    unsigned serverid;
    std::string name;
    std::string host;
    unsigned short port;
    std::string version;
    unsigned ping;
    std::string map;
    unsigned curplayers;
    unsigned maxplayers;
    bool has_password;
};

#endif // !liblobby_include_liblobby_LobbyServerInfo_h
