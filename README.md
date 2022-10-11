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

Para efectos de este ejemplo, se maneja una pila con los nodos del árbol de puertas (generado aleatoriamente).
Se ilustra un algoritmo que recorre rutas aleatorias hasta llegar a un punto muerto o agotar las opciones
visitadas. Si bien la solucion es limitada, sirve de base para elaborar un comportamiento de mayor complejidad
para las estrategias de un personaje. Por ejemplo, se puede agregar un condicion que detiene la busqueda de puertas
si la posición actual tiene un túnel. Asimismo, la navegación de este puede modelarse de forma similar.

UPDATE:
Adicional al ejemplo anterior, se implementó una versión alterna del mismo método que optimiza el descarte
de rutas ya visitadas sin la necesidad de una busqueda secuencial de nodos pendientes. Para ello se rediseño
la solución de forma que se maneja una pila de opciones, las cuales se representan mediante indices.
La búsqueda de este contrasta en que no es aleatoria, pero sigue los mismos principios. La pila de opciones
se va llenando con el tamaño del listado children de un nodo. Para saber si retroceder o avanzar, basta revisar
si el tope > 0. Cuando se avanza, se decrementa dicho valor antes de tomar el nodo siguiente y se apila la
cantidad nueva de opciones. Al retroceder, descartamos el tope de la pila y se continua reduciendo las opciones
previas de ser posible.
