bool updateTCP(int tcp_val[], const int js_val[], const int adj[], const int &n)
{
  // tolerances for joystick parameters
  const int TCP_MID = 255/2;
  const int JS_MID = 600;
  const int JS_RNG = 200;

  for (int i(0); i < n; ++i) {
    if (js_val[i] > (JS_MID + JS_RNG) && tcp_val[i] < 255) {
      tcp_val[i] = tcp_val[i] + 1;
    }
    else if (js_val[i] < (JS_MID - JS_RNG) && tcp_val[i] > -255) {
      tcp_val[i] = tcp_val[i] - 1;
    }
  }
      
  return true;
}
