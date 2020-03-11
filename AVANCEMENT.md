### Etat de l'avancement du projet.

Pour le moment, l'intégralité des fonctionnalités de base ont été développés, mais ne sont pas toutes complètement fusionnés.
De plus, une review du code afin de permettre de corriger toutes les erreurs signalées par valgrind (hors erreurs gtk) est prévu.  

server :  
    Contiens les fonctions liés à la lecture de données cbor.  
    Il contient un XMLController afin de lancer la mise à jour de l'image à la réception d'une données.  
    ERROR : Depuis la création d'un thread pour la fenetre Gtk, la lecture des données reçus par cbor est corrompu ([Lignes 105 - 113](src/server.cpp)).
    
XMLController :  
    Contiens les fonction permettant la lecture / modifications des balises 'Driven' du fichier XML.  
    Contiens un serverUI afin de lancer la mise à jour de l'affichage lors de la modification du XML.  
    La fonction 'update' n'est pas encore intégrée au master.  
    
serverUI :  
    Contiens l'intégralité des fonctions de gestion de la fenêtre Gtk.  
    L'instance de la classe lance la fenêtre Gtk dans un std::thread séparé.
    
client :  
    Application client très simple, permettant l'envoie d'un couple (x, y) d'entier au format Cbor, puis se ferme.
    
GTKClient :  
    Interface pour client développé en bonus (Pas intégré / complétée).  
    
main :  
    Créer une instance de server, puis le démarrer 'server->start()';  