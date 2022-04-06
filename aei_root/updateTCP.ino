bool updateTCP(int tcp_val[], const int js_val[], const int &tcp_max, const int &n)
{
  
  // tolerances for joystick parameters
  const int JS_MID = 500;
  const int JS_TOL = 300;

  for (int i(0); i < n; ++i) {
    const int j = 2*i;
    if (js_val[j] > (JS_MID + JS_TOL) && tcp_val[j] < tcp_max && tcp_val[j+1] == 0) {
      tcp_val[j] = tcp_val[j] + 1;
    }
    else if (js_val[j] < (JS_MID - JS_TOL) && tcp_val[j] > 0) {
      tcp_val[j] = tcp_val[j] - 1;
    }

    if (js_val[j+1] < (JS_MID - JS_TOL) && tcp_val[j+1] < tcp_max && tcp_val[j] == 0) {
      tcp_val[j+1] = tcp_val[j+1] + 1;
    }
    else if (js_val[j+1] > (JS_MID + JS_TOL) && tcp_val[j+1] > 0) {
      tcp_val[j+1] = tcp_val[j+1] - 1;
    }
  }
      
  return true;
}
