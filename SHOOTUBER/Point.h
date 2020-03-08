#pragma once
#include <cmath>

typedef struct SVector2 {
	float											x, y;
													SVector2														()													= default;
													SVector2														( float _x, float _y )								: x(_x), y(_y)									{}
	SVector2										operator +														( const SVector2& other )					const	{ return SVector2( x + other.x, y + other.y );	}
	SVector2&										operator +=														( const SVector2& other )							{ x += other.x	; y += other.y	; return *this;	}
	SVector2&										operator *=														( float scalar )									{ x *= scalar	; y *= scalar	; return *this;	}
	
	float											Length															()											const	{	
		float												vectorSquaredLength												= x * x + y * y;
		return vectorSquaredLength ? ::std::sqrtf( vectorSquaredLength ) : 0; 
	}
	float											AngleWith														( const SVector2& v )						const	{
		float												fLengthsProduct													= (this->Length() * v.Length());
		return fLengthsProduct ? (float)acos( Dot(v) / fLengthsProduct ) : 0;
	}
	float											Dot																( const SVector2& other )					const	{ return x * other.x + y * other.y; } 
	void											Scale															( float _scalar )									{
		x												*= _scalar; 
		y												*= _scalar;
	}	
	void											Normalize														()													{
		float												vectorSquaredLength												= x * x + y * y;
		if( vectorSquaredLength ) {
			vectorSquaredLength								= ::std::sqrtf( vectorSquaredLength );
			x												= x / vectorSquaredLength;
			y												= y / vectorSquaredLength;
		}
	}
	SVector2&										Rotate															( float _theta_in_rads )							{
		float												theta															= _theta_in_rads;
		float												cs																= ::std::cosf(theta);
		float												sn																= ::std::sinf(theta);

		float												px																= x * cs - y * sn; 
		float												py																= x * sn + y * cs;

		x												= px;
		y												= py;
		return *this;
	}
} SPoint2;