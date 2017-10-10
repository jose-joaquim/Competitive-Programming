double ternarySearch(double L, double R){
  double right = R, left = L, leftThird, rightThird;
  while(true){
    if(fabs(right - left) < EPS){
      break;
    }

    leftThird = left + (right - left)/3.0;
    rightThird = right - (right - left)/3.0;

    if(dijkstra(leftThird) < dijkstra(rightThird)){
      left = leftThird;
    }else right = rightThird;
    
  }
  return (left + right)/2.0;
}
