int updateTCP(const int& pin, const int& val)
{
  // tolerances for joystick parameters
  const int JS_MID = 600;
  const int JS_RNG = 100;

  if (val > (JS_MID + JS_RNG) && val < 255) {
    return 1;
  }
  else if (val < (JS_MID - JS_RNG) && val > 0) {
    return -1;
  }
      
  return 0;
}
