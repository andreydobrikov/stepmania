/* NoteDataWithScoring - NoteData with scores for each TapNote and HoldNote. */

#ifndef NOTEDATAWITHSCORING_H
#define NOTEDATAWITHSCORING_H

#include "GameConstantsAndTypes.h"
#include "NoteData.h"
#include "PlayerNumber.h"
#include <map>

struct RadarValues;

class NoteDataWithScoring : public NoteData
{
public:
	NoteDataWithScoring();
	void Init();

	// statistics
	int GetNumTapNotesWithScore( TapNoteScore tns, const float fStartBeat = 0, const float fEndBeat = -1 ) const;
	int GetNumNWithScore( TapNoteScore tns, int MinTaps, const float fStartBeat = 0, const float fEndBeat = -1 ) const;
	int GetNumHoldNotesWithScore( HoldNoteScore hns, const float fStartBeat = 0, const float fEndBeat = -1 ) const;
	int GetSuccessfulMines( const float fStartBeat = 0, const float fEndBeat = -1 ) const;
	int GetSuccessfulHands( const float fStartBeat = 0, const float fEndBeat = -1 ) const;

	bool IsRowCompletelyJudged(unsigned row) const;
	TapNoteScore MinTapNoteScore(unsigned row) const;
	TapNoteScore LastTapNoteScore(unsigned row) const;

	void GetActualRadarValues( PlayerNumber pn, float fSongSeconds, RadarValues& out ) const;

private:
	int LastTapNoteScoreTrack(unsigned row) const;

	float GetActualStreamRadarValue( float fSongSeconds, PlayerNumber pn ) const;
	float GetActualVoltageRadarValue( float fSongSeconds, PlayerNumber pn ) const;
	float GetActualAirRadarValue( float fSongSeconds, PlayerNumber pn ) const;
	float GetActualFreezeRadarValue( float fSongSeconds, PlayerNumber pn ) const;
	float GetActualChaosRadarValue( float fSongSeconds, PlayerNumber pn ) const;
};

#endif

/*
 * (c) 2001-2004 Chris Danford, Glenn Maynard
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
