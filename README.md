# Caso_4_Preliminar

Este código es un ejemplo de la utilidad que ofrecen las pilas para el programa del Caso 4.
Dicho programa es contextualizado como un juego de estrategia donde los personajes de un jugador
navegan una red de puertas en busca de tuneles, cuya estructura es un arbol con camaras que contiene
minerales a cierta profundidad.

La pilas resultan una estructura útil para representar la ruta actual que lleva un personaje en determinado
momento, pues permite llevar un orden de los movimientos en la red. Al escoger un camino, este se apila al
contenedor. Para retroceder en la ruta, quitamos de la pila tantas veces como queramos retroceder. Podemos
ver aplicaciones reales de este principio en los directorios de una computadora o en el historial de un
navegador o en software de edición.

Para efectos de este ejemplo, se maneja una pila con los nodos del árbol de puertas (generado aleatoriamente=.
Se ilustra un algoritmo que recorre rutas aleatorias hasta llegar a un punto muerto o agotar las opciones
visitadas. Si bien la solucion es limitada, sirve de base para elaborar un comportamiento de mayor complejidad
para las estrategias de un personaje. Por ejemplo, se puede agregar un condicion que detiene la busqueda de puertas
si la posición actual tiene un túnel. Asimismo, la navegación de este puede modelarse de forma similar.
