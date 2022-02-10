int updateTCP(const int& pin, const int& pin_val, const int& JS_VAL)
{
  // tolerances for joystick parameters
  const int JS_MID = 600;
  const int JS_RNG = 200;

  if (JS_VAL > (JS_MID + JS_RNG) && pin_val < 255) {
    return 1;
  }
  else if (JS_VAL < (JS_MID - JS_RNG) && pin_val > -255) {
    return -1;
  }
      
  return 0;
}
