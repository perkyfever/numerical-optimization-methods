#include "exp.hpp"
#include <cmath>
#include <iostream>

#include "constants.hpp"

int main() {

  // Testing for float values

  // Testing for x <= 0
  float negFloatMaxErr = 0.0f; // absolute error
  float negFloatTests[] = {
      -20.,         -19.59183673, -19.18367347, -18.7755102,  -18.36734694,
      -17.95918367, -17.55102041, -17.14285714, -16.73469388, -16.32653061,
      -15.91836735, -15.51020408, -15.10204082, -14.69387755, -14.28571429,
      -13.87755102, -13.46938776, -13.06122449, -12.65306122, -12.24489796,
      -11.83673469, -11.42857143, -11.02040816, -10.6122449,  -10.20408163,
      -9.79591837,  -9.3877551,   -8.97959184,  -8.57142857,  -8.16326531,
      -7.75510204,  -7.34693878,  -6.93877551,  -6.53061224,  -6.12244898,
      -5.71428571,  -5.30612245,  -4.89795918,  -4.48979592,  -4.08163265,
      -3.67346939,  -3.26530612,  -2.85714286,  -2.44897959,  -2.04081633,
      -1.63265306,  -1.2244898,   -0.81632653,  -0.40816327,  0.};
  for (auto x : negFloatTests) {
    auto stdExp = std::exp(x);          // expected exponent
    auto impExp = ADAAI::Exp<float>(x); // implemented exponent
    negFloatMaxErr = std::max(negFloatMaxErr, std::abs(stdExp - impExp));
  }

  // Testing for x > 0
  float posFloatMaxErr = 0.0f; // relative error
  float posFloatTests[] = {
      0.,          0.40816327,  0.81632653,  1.2244898,   1.63265306,
      2.04081633,  2.44897959,  2.85714286,  3.26530612,  3.67346939,
      4.08163265,  4.48979592,  4.89795918,  5.30612245,  5.71428571,
      6.12244898,  6.53061224,  6.93877551,  7.34693878,  7.75510204,
      8.16326531,  8.57142857,  8.97959184,  9.3877551,   9.79591837,
      10.20408163, 10.6122449,  11.02040816, 11.42857143, 11.83673469,
      12.24489796, 12.65306122, 13.06122449, 13.46938776, 13.87755102,
      14.28571429, 14.69387755, 15.10204082, 15.51020408, 15.91836735,
      16.32653061, 16.73469388, 17.14285714, 17.55102041, 17.95918367,
      18.36734694, 18.7755102,  19.18367347, 19.59183673, 20.};
  for (auto x : posFloatTests) {
    auto stdExp = std::exp(x);          // expected exponent
    auto impExp = ADAAI::Exp<float>(x); // implemented exponent
    auto diff = std::abs(stdExp - impExp);
    posFloatMaxErr = std::max(posFloatMaxErr, diff / stdExp);
  }

  std::cout << "RESULTS FOR FLOAT VALUES: " << std::endl;
  std::cout << "=> EPS is set to be " << 10.0 * ADAAI::Eps<float> << std::endl;
  std::cout << "=> Max absolute error for x <= 0: " << negFloatMaxErr
            << std::endl;
  std::cout << "=> Max relative error for x > 0:  " << posFloatMaxErr
            << std::endl;
  std::cout << std::endl;

  // Testing for double values

  // Testing for x <= 0
  double negDoubleMaxErr = 0.0f; // absolute error
  double negDoubleTests[] = {
      -40.,         -39.49367089, -38.98734177, -38.48101266, -37.97468354,
      -37.46835443, -36.96202532, -36.4556962,  -35.94936709, -35.44303797,
      -34.93670886, -34.43037975, -33.92405063, -33.41772152, -32.91139241,
      -32.40506329, -31.89873418, -31.39240506, -30.88607595, -30.37974684,
      -29.87341772, -29.36708861, -28.86075949, -28.35443038, -27.84810127,
      -27.34177215, -26.83544304, -26.32911392, -25.82278481, -25.3164557,
      -24.81012658, -24.30379747, -23.79746835, -23.29113924, -22.78481013,
      -22.27848101, -21.7721519,  -21.26582278, -20.75949367, -20.25316456,
      -19.74683544, -19.24050633, -18.73417722, -18.2278481,  -17.72151899,
      -17.21518987, -16.70886076, -16.20253165, -15.69620253, -15.18987342,
      -14.6835443,  -14.17721519, -13.67088608, -13.16455696, -12.65822785,
      -12.15189873, -11.64556962, -11.13924051, -10.63291139, -10.12658228,
      -9.62025316,  -9.11392405,  -8.60759494,  -8.10126582,  -7.59493671,
      -7.08860759,  -6.58227848,  -6.07594937,  -5.56962025,  -5.06329114,
      -4.55696203,  -4.05063291,  -3.5443038,   -3.03797468,  -2.53164557,
      -2.02531646,  -1.51898734,  -1.01265823,  -0.50632911,  0.};
  for (auto x : negDoubleTests) {
    auto stdExp = std::exp(x);           // expected exponent
    auto impExp = ADAAI::Exp<double>(x); // implemented exponent
    negDoubleMaxErr = std::max(negDoubleMaxErr, std::abs(stdExp - impExp));
  }

  // Testing for x > 0
  double posDoubleMaxErr = 0.0f; // relative error
  double posDoubleTests[] = {
      0.,          0.50632911,  1.01265823,  1.51898734,  2.02531646,
      2.53164557,  3.03797468,  3.5443038,   4.05063291,  4.55696203,
      5.06329114,  5.56962025,  6.07594937,  6.58227848,  7.08860759,
      7.59493671,  8.10126582,  8.60759494,  9.11392405,  9.62025316,
      10.12658228, 10.63291139, 11.13924051, 11.64556962, 12.15189873,
      12.65822785, 13.16455696, 13.67088608, 14.17721519, 14.6835443,
      15.18987342, 15.69620253, 16.20253165, 16.70886076, 17.21518987,
      17.72151899, 18.2278481,  18.73417722, 19.24050633, 19.74683544,
      20.25316456, 20.75949367, 21.26582278, 21.7721519,  22.27848101,
      22.78481013, 23.29113924, 23.79746835, 24.30379747, 24.81012658,
      25.3164557,  25.82278481, 26.32911392, 26.83544304, 27.34177215,
      27.84810127, 28.35443038, 28.86075949, 29.36708861, 29.87341772,
      30.37974684, 30.88607595, 31.39240506, 31.89873418, 32.40506329,
      32.91139241, 33.41772152, 33.92405063, 34.43037975, 34.93670886,
      35.44303797, 35.94936709, 36.4556962,  36.96202532, 37.46835443,
      37.97468354, 38.48101266, 38.98734177, 39.49367089, 40.};
  for (auto x : posDoubleTests) {
    auto stdExp = std::exp(x);           // expected exponent
    auto impExp = ADAAI::Exp<double>(x); // implemented exponent
    auto diff = std::abs(stdExp - impExp);
    posDoubleMaxErr = std::max(posDoubleMaxErr, diff / stdExp);
  }

  std::cout << "RESULTS FOR DOUBLE VALUES: " << std::endl;
  std::cout << "=> EPS is set to be " << 10.0 * ADAAI::Eps<double> << std::endl;
  std::cout << "=> Max absolute error for x <= 0: " << negDoubleMaxErr
            << std::endl;
  std::cout << "=> Max relative error for x > 0:  " << posDoubleMaxErr
            << std::endl;
  std::cout << std::endl;

  // Testing for long double values

  // Testing for x <= 0
  long double negLongDoubleMaxErr = 0.0f; // absolute error
  long double negLongDoubleTests[] = {
      -80.,         -79.32773109, -78.65546218, -77.98319328, -77.31092437,
      -76.63865546, -75.96638655, -75.29411765, -74.62184874, -73.94957983,
      -73.27731092, -72.60504202, -71.93277311, -71.2605042,  -70.58823529,
      -69.91596639, -69.24369748, -68.57142857, -67.89915966, -67.22689076,
      -66.55462185, -65.88235294, -65.21008403, -64.53781513, -63.86554622,
      -63.19327731, -62.5210084,  -61.8487395,  -61.17647059, -60.50420168,
      -59.83193277, -59.15966387, -58.48739496, -57.81512605, -57.14285714,
      -56.47058824, -55.79831933, -55.12605042, -54.45378151, -53.78151261,
      -53.1092437,  -52.43697479, -51.76470588, -51.09243697, -50.42016807,
      -49.74789916, -49.07563025, -48.40336134, -47.73109244, -47.05882353,
      -46.38655462, -45.71428571, -45.04201681, -44.3697479,  -43.69747899,
      -43.02521008, -42.35294118, -41.68067227, -41.00840336, -40.33613445,
      -39.66386555, -38.99159664, -38.31932773, -37.64705882, -36.97478992,
      -36.30252101, -35.6302521,  -34.95798319, -34.28571429, -33.61344538,
      -32.94117647, -32.26890756, -31.59663866, -30.92436975, -30.25210084,
      -29.57983193, -28.90756303, -28.23529412, -27.56302521, -26.8907563,
      -26.21848739, -25.54621849, -24.87394958, -24.20168067, -23.52941176,
      -22.85714286, -22.18487395, -21.51260504, -20.84033613, -20.16806723,
      -19.49579832, -18.82352941, -18.1512605,  -17.4789916,  -16.80672269,
      -16.13445378, -15.46218487, -14.78991597, -14.11764706, -13.44537815,
      -12.77310924, -12.10084034, -11.42857143, -10.75630252, -10.08403361,
      -9.41176471,  -8.7394958,   -8.06722689,  -7.39495798,  -6.72268908,
      -6.05042017,  -5.37815126,  -4.70588235,  -4.03361345,  -3.36134454,
      -2.68907563,  -2.01680672,  -1.34453782,  -0.67226891,  0.};
  for (auto x : negLongDoubleTests) {
    auto stdExp = std::exp(x);                // expected exponent
    auto impExp = ADAAI::Exp<long double>(x); // implemented exponent
    negLongDoubleMaxErr =
        std::max(negLongDoubleMaxErr, std::abs(stdExp - impExp));
  }

  // Testing for x > 0
  long double posLongDoubleMaxErr = 0.0f; // relative error
  long double posLongDoubleTests[] = {
      0.,          0.67226891,  1.34453782,  2.01680672,  2.68907563,
      3.36134454,  4.03361345,  4.70588235,  5.37815126,  6.05042017,
      6.72268908,  7.39495798,  8.06722689,  8.7394958,   9.41176471,
      10.08403361, 10.75630252, 11.42857143, 12.10084034, 12.77310924,
      13.44537815, 14.11764706, 14.78991597, 15.46218487, 16.13445378,
      16.80672269, 17.4789916,  18.1512605,  18.82352941, 19.49579832,
      20.16806723, 20.84033613, 21.51260504, 22.18487395, 22.85714286,
      23.52941176, 24.20168067, 24.87394958, 25.54621849, 26.21848739,
      26.8907563,  27.56302521, 28.23529412, 28.90756303, 29.57983193,
      30.25210084, 30.92436975, 31.59663866, 32.26890756, 32.94117647,
      33.61344538, 34.28571429, 34.95798319, 35.6302521,  36.30252101,
      36.97478992, 37.64705882, 38.31932773, 38.99159664, 39.66386555,
      40.33613445, 41.00840336, 41.68067227, 42.35294118, 43.02521008,
      43.69747899, 44.3697479,  45.04201681, 45.71428571, 46.38655462,
      47.05882353, 47.73109244, 48.40336134, 49.07563025, 49.74789916,
      50.42016807, 51.09243697, 51.76470588, 52.43697479, 53.1092437,
      53.78151261, 54.45378151, 55.12605042, 55.79831933, 56.47058824,
      57.14285714, 57.81512605, 58.48739496, 59.15966387, 59.83193277,
      60.50420168, 61.17647059, 61.8487395,  62.5210084,  63.19327731,
      63.86554622, 64.53781513, 65.21008403, 65.88235294, 66.55462185,
      67.22689076, 67.89915966, 68.57142857, 69.24369748, 69.91596639,
      70.58823529, 71.2605042,  71.93277311, 72.60504202, 73.27731092,
      73.94957983, 74.62184874, 75.29411765, 75.96638655, 76.63865546,
      77.31092437, 77.98319328, 78.65546218, 79.32773109, 80.};
  for (auto x : posLongDoubleTests) {
    auto stdExp = std::exp(x);                // expected exponent
    auto impExp = ADAAI::Exp<long double>(x); // implemented exponent
    long double diff = std::abs(stdExp - impExp);
    posLongDoubleMaxErr = std::max(posLongDoubleMaxErr, diff / stdExp);
  }

  std::cout << "RESULTS FOR LONG DOUBLE VALUES: " << std::endl;
  std::cout << "=> EPS is set to be "
            << 10.0 * ADAAI::Eps<long double> << std::endl;
  std::cout << "=> Max absolute error for x <= 0: " << negLongDoubleMaxErr
            << std::endl;
  std::cout << "=> Max relative error for x > 0:  " << posLongDoubleMaxErr
            << std::endl;

  // LOCAL RESULTS
  // RESULTS FOR FLOAT VALUES:
  // => EPS is set to be 1.19209e-06
  // => Max absolute error for x <= 0: 4.17233e-07
  // => Max relative error for x > 0:  1.24975e-06
  //
  // RESULTS FOR DOUBLE VALUES:
  // => EPS is set to be 2.22045e-15
  // => Max absolute error for x <= 0: 1.11022e-16
  // => Max relative error for x > 0:  4.24767e-15
  //
  // RESULTS FOR LONG DOUBLE VALUES:
  // => EPS is set to be 1.0842e-18
  // => Max absolute error for x <= 0: 4.06576e-20
  // => Max relative error for x > 0:  3.49518e-18
}
