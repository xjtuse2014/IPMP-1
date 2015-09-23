/*
 * fnd.c
 *
 *  Created on: Aug 25, 2015
 *      Author: syq
 */
double rndl(r)
double *r;
{
	int m;
	double s,u,v,p;
	s=65536.0;//m=2^16
	u=2053.0;
	v=13849.0;
	m=(int)(*r/s);
	*r=*r-m*s;
	*r=u*(*r)+v;
	m=(int)(*r/s);
	*r=*r-m*s;
	p=*r/s;
	return (p);
}



