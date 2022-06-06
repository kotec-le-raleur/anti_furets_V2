# anti_furets_V2
Anti_furets V2, avec plus de trucs super extra méga cools

Dispositif générateur d'ultra-sons et de flashs lumineux pour effrayer les nuisibles dans un grenier

Ce petit montage trivial , garanti sans NE555, génére des suites aléatoires de sons dans la gamme des 15 à 22 kilo Hertz. Des flashs lumineux peuvent être ajoutés avec une ampoule LED 12V ou un ruban de leds. On peut aussi mettre un relais pour augmenter la puissance, mais il faudra que la charge et le relais supportent les marche/arret sans griller. La consommation sans l'ampoule LED est de 50 mA et une prise murale alim 12V suffit largement ! Si une diode zéner est utilisée à la place du régulateur, vérifier que la tension à ses bornes ne dépasse pas 5V avant de plugger le µcontrôleur. Il faut penser à installer le core ATTiny85 qui implémente la fonction Tone() avant de compiler/télécharger le programme Ajouter dans le menu de l'IDE Arduino la ligne : http://drazzy.com/package_drazzy.com_index.json
