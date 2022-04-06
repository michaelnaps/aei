bool resetTCP(int tcp_val[], const int &js_button, const int &tcp_max, const int &n)
{

  if (!js_button) {
    for (int i(0); i < n; ++i) {
      tcp_val[i] = 0;
    }
  }

  return true;
}
