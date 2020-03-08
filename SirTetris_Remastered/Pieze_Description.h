#pragma once

#define															PIEZE_SIZE											4

const unsigned char													barraH[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		,
																																176	, 176	, 176	, 176	,
																																0	, 0		, 0		, 0		};

const unsigned char													barraV[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 0		, 176	, 0		,
																																0	, 0		, 176	, 0		,
																																0	, 0		, 176	, 0		,
																																0	, 0		, 176	, 0		};

const unsigned char													square[PIEZE_SIZE][PIEZE_SIZE]		=					{	176	, 176	, 0		, 0		,
																																176	, 176	, 0		, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													dosH[PIEZE_SIZE][PIEZE_SIZE]		=					{	178	, 178	, 0		, 0		,
																																0	, 178	, 178	, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													dosV[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 0		, 178	, 0		,
																																0	, 178	, 178	, 0		,
																																0	, 178	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eseH[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 177	, 177	, 0		,
																																177	, 177	, 0		, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eseV[PIEZE_SIZE][PIEZE_SIZE]		=					{	177	, 0		, 0		, 0		,
																																177	, 177	, 0		, 0		,
																																0	, 177	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													podioUp[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 176	, 0		, 0		,
																																176	, 176	, 176	, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													podioLeft[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 176	, 0		, 0		,
																																176	, 176	, 0		, 0		,
																																0	, 176	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													podioDown[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 0		, 0		, 0		,
																																176	, 176	, 176	, 0		,
																																0	, 176	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													podioRight[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 176	, 0		, 0		,
																																0	, 176	, 176	, 0		,
																																0	, 176	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleUp[PIEZE_SIZE][PIEZE_SIZE]		=					{	177	, 177	, 0		, 0		,
																																0	, 177	, 0		, 0		,
																																0	, 177	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleLeft[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 0		, 0		, 0		,
																																177	, 177	, 177	, 0		,
																																177	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleDown[PIEZE_SIZE][PIEZE_SIZE]		=					{	0	, 177	, 0		, 0		,
																																0	, 177	, 0		, 0		,
																																0	, 177	, 177	, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleRight[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 0		, 177	, 0		,
																																177	, 177	, 177	, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleInvUp[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 178	, 178	, 0		,
																																0	, 178	, 0		, 0		,
																																0	, 178	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleInvLeft[PIEZE_SIZE][PIEZE_SIZE]	=					{	178	, 0		, 0		, 0		,
																																178	, 178	, 178	, 0		,
																																0	, 0		, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleInvDown[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 178	, 0		, 0		,
																																0	, 178	, 0		, 0		,
																																178	, 178	, 0		, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char													eleInvRight[PIEZE_SIZE][PIEZE_SIZE]	=					{	0	, 0		, 0		, 0		,
																																178	, 178	, 178	, 0		,
																																0	, 0		, 178	, 0		,
																																0	, 0		, 0		, 0		};

const unsigned char	titleS[7][3]={		0	, 0		, 0		,
										176	, 176	, 176	,
										176	, 0		, 0		,
										178	, 178	, 0		,
										0	, 178	, 178	,
										0	, 0		, 176	,
										176	, 176	, 176	};

const unsigned char	titleI[7][3]={		0	,	177	, 177	,
										0	,	177	, 177	,
										0	,	0	, 0		,
										0	,	177	, 177	,
										0	,	177	, 177	,
										0	,	177	, 177	,
										0	,	177	, 177	};

const unsigned char	titleR[7][5]={		 0	, 0	,	0	, 0	 , 0	,
										 0	, 176,	176	, 176, 0	,
										 0	, 176,	0	, 0	 , 176	,
										 0	, 177,	176	, 176, 176	,
										 0	, 177,	0	, 176, 0	,
										 0	, 177,	0	, 176, 176	,
										 0	, 177,	0	, 0	 , 176	};

const unsigned char	titleT[7][6]={		 0	 ,	0	, 0	 , 0	, 0	 ,0		,
										 178,	178	, 178, 176	, 176,176	,
										 0	 ,	0	, 178, 176	, 0	 ,0		,
										 0	 ,	0	, 177, 177	, 0	 ,0		,
										 0	 ,	0	, 177, 177	, 0	 ,0		,
										 0	 ,	0	, 177, 177	, 0	 ,0		,
										 0	 ,	0	, 177, 177	, 0	 ,0		};

const unsigned char	titleE[7][4]={		 0	, 0   ,	0	, 0		,
										 177, 177 ,	177	, 177	,
										 178, 178 ,	0	, 0		,
										 0  , 178 ,	178	, 0		,
										 0	, 176 ,	176	, 0		,
										 176, 176 ,	0	, 0		,
										 177, 177 ,	177	, 177	};

const unsigned char	titleEe[7][5]={		 0	, 0		, 0		, 0		, 0		,
										 177, 177	, 177	, 177	, 0		,
										 178, 178	, 0		, 0		, 0		,
										 0  , 178	, 178	, 0		, 0		,
										 0	, 0		, 176	, 176	, 0		,
										 0	, 0		, 0		, 176	, 176	,
										 0	, 177	, 177	, 177	, 177	};

//{	  0	 ,	0	, 0	 , 0	, 0	 ,0		, 0	, 0	 , 0   ,	0	, 0	 , 0	, 0	,	0	, 0	 , 0	, 0	,	0	, 0	 , 0	, 0	 , 0	,	0	, 177	, 177	, 0	, 0		, 0		, 0		,
//	  178,	178	, 178, 176	, 176,176	, 0	, 177, 177 ,	177	, 177, 0	, 176,	176	, 176, 178	, 178,	178	, 0	 , 176	, 176, 176	,	0	, 177	, 177	, 0	, 176	, 176	, 176	,
//	  0	 ,	0	, 178, 176	, 0	 ,0		, 0	, 178, 178 ,	0	, 0	 , 0	, 0	,	0	, 176, 178	, 0	,	0	, 176, 0	, 0	 , 176	,	0	, 0		, 0		, 0	, 0		, 0		, 176	,
//	  0	 ,	0	, 177, 177	, 0	 ,0		, 0	, 0  , 178 ,	178	, 0	 , 0	, 0	,	0	, 177, 177	, 0	,	0	, 176, 176	, 176, 177	,	0	, 177	, 177	, 0	, 0		, 178	, 178	,
//	  0	 ,	0	, 177, 177	, 0	 ,0		, 0	, 0	 , 176 ,	176	, 0	 , 0	, 0	,	0	, 177, 177	, 0	,	0	, 0	 , 176	, 0	 , 177	,	0	, 177	, 177	, 0	, 178	, 178	, 0		,
//	  0	 ,	0	, 177, 177	, 0	 ,0		, 0	, 176, 176 ,	0	, 0	 , 0	, 0	,	0	, 177, 177	, 0	,	0	, 176, 176	, 0	 , 177	,	0	, 177	, 177	, 0	, 176	, 0		, 0		,
//	  0	 ,	0	, 177, 177	, 0	 ,0		, 0	, 177, 177 ,	177	, 177, 0	, 0	,	0	, 177, 177	, 0	,	0	, 176, 0	, 0	 , 177	,	0	, 177	, 177	, 0	, 176	, 176	, 176	};

const unsigned char													textMenuOne[7]	=	{'1', 'p', 'l', 'a', 'y', 'e', 'r'};
const unsigned char													textMenuOneM[7]	=	{'1', 'P', 'L', 'A', 'Y', 'E', 'R'};
const unsigned char													textMenuTwo[8]	=	{'2', 'p', 'l', 'a', 'y', 'e', 'r', 's'};
const unsigned char													textMenuTwoM[8]	=	{'2', 'P', 'L', 'A', 'Y', 'E', 'R', 'S'};

const unsigned char													textNext[4]	={'N', 'E', 'X', 'T'};

const unsigned char													sirTeris[PIEZE_SIZE+1][PIEZE_SIZE]	=					{	0	,	0	, 0		,	0	,
																																0	,	1	, 0		,	0	,
																																192	,	179	, 217	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 179	,	0	};

const unsigned char													sirTerisTwo[PIEZE_SIZE+1][PIEZE_SIZE]	=				{	0	,	1	, 0		,	0	,
																																218	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																217	,	0	, 217	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char													anothersirTeris[PIEZE_SIZE+1][PIEZE_SIZE]	=			{	0	,	0	, 0		,	0	,
																																0	,	2	, 0		,	0	,
																																192	,	179	, 217	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 179	,	0	};

const unsigned char													anothersirTerisTwo[PIEZE_SIZE+1][PIEZE_SIZE]	=		{	0	,	2	, 0		,	0	,
																																218	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																217	,	0	, 217	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char													sirTetrisTitle[PIEZE_SIZE+1][PIEZE_SIZE]	={				0	,	1	, 0		,	0	,
																																192	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																217	,	0	, 179	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char													sirTetrisTitleTwo[PIEZE_SIZE+1][PIEZE_SIZE]	={				0	,	1	, 0	,	0	,
																																218	,	179	, 217	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 217	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char													sirTetrisTitleThree[PIEZE_SIZE+1][PIEZE_SIZE]	={			0	,	1	, 0		,	0	,
																																218	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 179	,	0	,
																																0	,	0	, 0		,	0	};


const unsigned char											anothersirTetrisTitle[PIEZE_SIZE+1][PIEZE_SIZE]			=		{	0	,	2	, 0		,	0	,
																																192	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																192	,	0	, 179	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char											anothersirTetrisTitleTwo[PIEZE_SIZE+1][PIEZE_SIZE]		=		{	0	,	2	, 0		,	0	,
																																218	,	179	, 217	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 192	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char											anothersirTetrisTitleThree[PIEZE_SIZE+1][PIEZE_SIZE]	=		{	0	,	2	, 0		,	0	,
																																218	,	179	, 191	,	0	,
																																0	,	194	, 0		,	0	,
																																179	,	0	, 179	,	0	,
																																0	,	0	, 0		,	0	};

const unsigned char													textTitle[5]			=	{	'W', 'H', 'A', 'T', '?'};

const unsigned char													textTitleTwo[3][10]		=	{	'D','U','D','E',' ','Y','O','U',' ',' ',
																									'A','R','E',' ','O','N',' ','T','H','E',
																									'W','R','O','N','G',' ','S','I','D','E'};

const unsigned char													textTitleThree[11]		=	{	'P','R','E','S','S',' ','E','N','T','E','R'};

const unsigned char													textTitleFour[4][17]	=	{	'D','O','N','`','T',' ','Y','O','U',' ','D','A','R','E',' ','T','O',
																									'T','A','L','K',' ','M','E',' ','L','I','K','E',' ','T','H','A','T',
																									'I','`','M',' ','T','H','E',' ','O','N','E',' ','T','R','U','E',' ',
																									'S','I','R',' ','T','E','T','R','I','S',' ',' ',' ',' ',' ',' ',' '};

const unsigned char													textTitleFive[2][16]	=	{	'P','R','E','P','A','R','E',' ','Y','O','U','R','S','E','L','F'	,
																									'L','E','T','`','S',' ','D','U','E','L',' ',' ',' ',' ',' ',' '	};
