co() {
    g++ -std=c++17 -Ofast -Wall -DLOCAL -o $1.o $1.cpp
}

co gen
co monitoringskipaths
co monitoringskipaths2

for i in {0..1000}
do
  ./gen.o > ski.in
  ./monitoringskipaths.o < ski.in > ski.out
  ./monitoringskipaths2.o < ski.in > ski2.out
  if ! cmp -s ski.out ski2.out; then
    echo "bad"
    break
  fi
done