bool printTCP(const int tcp_val[], const int adj[], const int &tcp_max, const int &n)
{
  const int TCP_MID = tcp_max/2;
  
  if (!Serial)
  {
    return false;
  }

  for (int i(0); i < n; ++i) {
    Serial.print(TCP_MID + adj[i] * tcp_val[i] / 2);
    if (i < n-1)
      Serial.print(", ");
    else
      Serial.println("");
  }
  
  return true;
}
