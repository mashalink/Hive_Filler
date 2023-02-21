echo "" > trace_filler

name+=$(cat ../author | tr '\n' '.')
maps=("map00" "map01" "map02")
players=("abanlin" "carli" "champely" "grati" "hcao" "superjeannot")
turns=("1" "2" "3" "4" "5")

for map in "${maps[@]}"
do
    echo "$map" >> trace_filler
    for player in "${players[@]}"
    do
        echo "against $player" >> trace_filler
        for i in "${turns[@]}"
        do
            run='./resources/filler_vm -q -p1 ../'
            run+=$name
            run+='filler -v -f resources/maps/'
            run+=$map
            run+=' -p2 resources/players/'
            run+=$player
            run+='.filler'
            $run
            if $(cat ./filler.trace | grep -q "$name") ; then
                echo "      won " >> trace_filler
            else 
                echo "      lost " >> trace_filler
            fi
        done
    done
done
