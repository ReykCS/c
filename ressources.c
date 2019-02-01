int isPrime(long number) {
  for ( long i = 2 ; i < number ; i++ )  {
    if ( number % i == 0 ) return 0;
  }
  return 1;
}

int numberLength(int number)  {
  if ( number >= 1000000) return 7;
  if ( number >= 100000) return 6;
  if ( number >= 10000) return 5;
  if ( number >= 1000) return 4;
  if ( number >= 100) return 3;
  if ( number >= 10) return 2;
  return 1;
}

int potenz(int n) {
  int sum = 1;
  for(int i = 1; i <= n; i++)  {
    sum *= 10;
  }
  return sum;
}

int potenzTwo(int n)  {
  int sum = 1;
  for ( int i = 0; i < n; i++)  {
    sum *= 2;
  }
  return sum;
}

int concat(int a, int b)  {
  if ( a == 0 ) return b;
  return a + (b * potenz(numberLength(a)));
}

int reverseNumber(int number) {
  int reverted = 0;
  int lim = numberLength(number);
  int zero = 1;
  for ( int i = 0; i < lim ; i++ ) {
    int num = number / potenz(lim-i-1);
    number %= potenz(lim-i-1);
    if ( num == 0 ) {
      zero = 10;
      continue;
    }
    reverted = concat(reverted, num * zero);
    zero = 1;
  }
  return reverted;
}

int convertDezimaltoBinary(int dezimal)  {
  int binaryComplete = 0;
  int mult = 1;
  while(dezimal >= 1)  {
    int binary = dezimal%2;
    dezimal = (dezimal - binary) / 2;
    if ( binary == 0 )  {
      mult *= 10;
      continue;
    }
    binaryComplete = concat(binaryComplete, binary * mult);
    mult = 1;
  }
  return binaryComplete;
}

int convertBinarytoDezimal(int binary)  {
  int boolean = 1;
  int counter = 1;
  int number = 0;
  while ( boolean == 1 )  {
    int dezimal = binary % potenz(1);
    number += (dezimal * potenzTwo(counter - 1));
    binary -= dezimal;
    binary /= 10;
    counter++;
    if ( binary == 0 ) break;
  }
  return number;
}

int convertDezimaltoOctal(int dezimal)  {
  int OctalComplete = 0;
  int mult = 1;
  while(dezimal > 0)  {
    int oktal = dezimal%8;
    dezimal = (dezimal - oktal) / 8;
    if ( oktal == 0 )  {
      mult *= 10;
      continue;
    }
    OctalComplete = concat(OctalComplete, oktal * mult);
    mult = 1;
  }
  return OctalComplete;
}
