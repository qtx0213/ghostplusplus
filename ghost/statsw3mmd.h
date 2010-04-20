/*

   Copyright [2008] [Trevor Hogan]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   CODE PORTED FROM THE ORIGINAL GHOST PROJECT: http://ghost.pwner.org/

*/

#ifndef STATSW3MMD_H
#define STATSW3MMD_H

//
// CStatsW3MMD
//

#include <QPair>
typedef QPair<uint32_t,QString> VarP;

class CStatsW3MMD : public CStats
{
private:
	QString m_Category;
	uint32_t m_NextValueID;
	uint32_t m_NextCheckID;
	QMap<uint32_t,QString> m_PIDToName;			// pid -> player name (e.g. 0 -> "Varlock") --- note: will not be automatically converted to lower case
	QMap<uint32_t,QString> m_Flags;				// pid -> flag (e.g. 0 -> "winner")
	QMap<uint32_t,bool> m_FlagsLeaver;			// pid -> leaver flag (e.g. 0 -> true) --- note: will only be present if true
	QMap<uint32_t,bool> m_FlagsPracticing;		// pid -> practice flag (e.g. 0 -> true) --- note: will only be present if true
	QMap<QString,QString> m_DefVarPs;				// varname -> value type (e.g. "kills" -> "int")
	QMap<VarP,int32_t> m_VarPInts;				// pid,varname -> value (e.g. 0,"kills" -> 5)
	QMap<VarP,double> m_VarPReals;				// pid,varname -> value (e.g. 0,"x" -> 0.8)
	QMap<VarP,QString> m_VarPStrings;				// pid,varname -> value (e.g. 0,"hero" -> "heroname")
	QMap<QString, QVector<QString> > m_DefEvents;	// event -> vector of arguments + format

public:
	CStatsW3MMD( CBaseGame *nGame, QString nCategory );
	virtual ~CStatsW3MMD( );

	virtual bool ProcessAction( CIncomingAction *Action );
	virtual void Save( CGHost *GHost, CGHostDB *DB, uint32_t GameID );
	virtual QVector<QString> TokenizeKey( QString key );
};

#endif
