bool writeTCP(const int tcp[], const int tcp_val[], const int &tcp_max, const int &n)
{  
  
  for (int i(0); i < n; ++i)
  {
    analogWrite(tcp[i], tcp_val[i]);
  }

  return true;
}
