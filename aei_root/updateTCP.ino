bool updateTCP(int tcp_val[], const int js_val[], const int adj[], const int &tcp_max, const int &n)
{
  // tolerances for joystick parameters
  const int JS_MID = 600;
  const int JS_TOL = 400;

  for (int i(0); i < n; ++i) {
    if (js_val[i] > (JS_MID + JS_TOL) && tcp_val[i] < tcp_max) {
      tcp_val[i] = tcp_val[i] + 1;
    }
    else if (js_val[i] < (JS_MID - JS_TOL) && tcp_val[i] > -tcp_max) {
      tcp_val[i] = tcp_val[i] - 1;
    }
  }
      
  return true;
}
