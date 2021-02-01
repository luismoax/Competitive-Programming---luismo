struct point
{
	ld x, y;
	point(){}
	point(ld x, ld y):x(x), y(y) {}
	void print()
	{
		cerr << "[" << x << "," << y << "]" << endl;
	}
};

// Euclidean Distance
ld dist(point a, point b)
{
	ld k = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(k);
}

// Orientation of point c from vector a->b (coolinear = 0, clockwise > 0, counter clockwise < 0)
int orientation(point a, point b, point c)
{
	return (a.y - b.y) * (b.x - c.x) - (b.y - c.y) * (a.x - b.x);
}
// Check whether a point is inside a segment
bool onSegment(point s, point e, point p)
{
	return 	orientation(s, e, p) == 0 && p.x >= min(s.x, e.x) && p.x <= max(s.x, e.x) &&
			p.y >= min(s.y, e.y) && p.y <= max(s.y, e.y);
}

// Check Whether two Segments (s1->e1, s2->e2) intersect
bool intersect(point s1, point e1, point s2, point e2)
{
	int or1 = orientation(s1, e1, s2);
	int or2 = orientation(s1, e1, e2);
	int or3 = orientation(s2, e2, s1);
	int or4 = orientation(s2, e2, e1);

	if(or1 * or2 < 0 && or3 * or4 < 0)
	{
		return true;
	}
    
	if(onSegment(s1, e1, s2))
	{
		return true;
	}
	if(onSegment(s1, e1, e2))
	{
		return true;
	}
	if(onSegment(s2, s2, s1))
	{
		return true;
	}
	if(onSegment(s2, e2, e1))
	{
		return true;
	}
	return false;
}


struct polarPoint
{
	double r, angle;
	polarPoint(){}
	polarPoint(double r, double angle):r(r), angle(angle) {}
	void print()
	{
		cerr << "[" << r << "," << angle << "]" << endl;
	}
	bool operator < (const polarPoint& other)
	{
		if(angle == other.angle)
			return r < other.r;
		return angle < other.angle;
	}
};

int quadrant(point p)
{
	int quad = 0;
	if(p.x > 0 && p.y > 0)
		quad = 1;
	if(p.x < 0 && p.y > 0)
		quad = 2;
	else if(p.x < 0 && p.y < 0)
		quad = 3;
	else if(p.x > 0 && p.y < 0)
		quad = 4;
	return quad;
}
// polar point from origin
polarPoint toPolar(point p)
{
	double angle = atan(p.y/p.x);
	// adjust taking care of quadrants
	double quad = quadrant(p);
	if(quad == 2 || p.y == 0 && p.x < 0)
		angle += M_PI;
	if(quad == 3)
		angle += M_PI;
	if(quad == 4 || p.y < 0 && p.x == 0)
		angle += 2*M_PI;	
	double r =sqrt(p.x*p.x + p.y*p.y);
	return polarPoint(r, angle);
}