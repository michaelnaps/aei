bool resetTCP(int tcp_val[], const int &js_button, const int &tcp_max, const int &n)
{
  const int TCP_MID = tcp_max/2;

  if (!js_button) {
    for (int i(0); i < n; ++i) {
      tcp_val[i] = 0;
    }
  }

  return true;
}
