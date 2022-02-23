bool writeTCP(const int tcp[], const int tcp_val[], const int adj[], const int &tcp_max, const int &n)
{
  const int TCP_MID = tcp_max/2;
  
  for (int i(0); i < n; ++i)
  {
    analogWrite(tcp[i], TCP_MID + adj[i] * tcp_val[i] / 2);
  }

  return true;
}
