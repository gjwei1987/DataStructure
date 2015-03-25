#ifndef __MY_TERM_H__
#define __MY_TERM_H__

struct Term {
   int degree;
   double coefficient;
   Term (int exponent = 0, double scalar = 0);
};


Term::Term(int exponent, double scalar)
{
   degree = exponent;
   coefficient = scalar;
}


#endif /*__MY_TERM_H__*/