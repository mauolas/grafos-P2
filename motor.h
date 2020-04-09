void motorsin(int matriz[][3]);


void motorsin(int matriz[][3]){
  motor=raiz;
  int temporal=89999;
  int bandera=0;

  if (motor->arr != NULL) {
    if((motor->arr)->cost < temporal){
      temporal=(motor->arr)->cost;
      bandera=1;
    }
  }
  if (motor->sig != NULL) {
    if((motor->sig)->cost < temporal){
      temporal=(motor->sig)->cost;
      bandera=2;
    }
  }
  if (motor->aba != NULL) {
    if((motor->aba)->cost < temporal){
      temporal=(motor->aba)->cost;
      bandera=3;
    }
  }
  if (motor->ant != NULL) {
    if((motor->ant)->cost < temporal){
      temporal=(motor->ant)->cost;
      bandera=1;
    }
  }



}
