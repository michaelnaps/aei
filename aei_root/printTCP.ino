bool printTCP(const int tcp_val[], const int &tcp_max, const int &n)
{
  
  if (!Serial)
  {
    return false;
  }

  for (int i(0); i < n; ++i) {
    Serial.print(tcp_val[i]);
    if (i < n-1)
      Serial.print(", ");
    else
      Serial.println("");
  }
  
  return true;
}
