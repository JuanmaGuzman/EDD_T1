# Tarea 1 2023-1
**Tarea del Ramo de Estructuras de Datos y Algoritmos: Simulación de Elecciones y Optimización de Algoritmos**

Este proyecto abarca la simulación de elecciones bajo diferentes sistemas de votación y la optimización de algoritmos para mejorar el rendimiento. Desde el procesamiento de votos y cálculo de resultados hasta la implementación de técnicas de ordenamiento y estructuras de datos avanzadas, el proyecto explora conceptos clave de programación y algoritmos.

**Objetivos:**
- Investigar y aplicar algoritmos y estructuras de datos para resolver problemas complejos.
- Utilizar técnicas de dividir y conquistar, y estrategias recursivas en la implementación de soluciones.
- Familiarizarse con la importancia de la complejidad computacional en la optimización de algoritmos.

**Parte 1: Matepossible**
Esta sección se centra en el procesamiento de votos y simulación de sistemas de votación. Los candidatos y votantes son analizados en un espectro ideológico. El sistema de votación STV es simulado con transferencias de votos según distancias ideológicas.

**Parte 2: DCCodersSort**
El objetivo es ordenar competidores en función de sus estadísticas de carreras. Se implementa el algoritmo QuickSort y se evalúa el rendimiento. Se busca optimizar la ordenación de datos en base a múltiples criterios.

**Parte 3: Mate, eso nunca paso.**
Se aborda un problema de simulación de colisiones en un escenario tridimensional. Se propone la optimización del algoritmo mediante la implementación de un KD-Tree (árbol de búsqueda en estructuras de datos).

**Código Base y Ejecución:**
Los programas se compilan con el comando 'make' y se ejecutan con parámetros de entrada y salida, procesando datos y generando resultados según el contexto de cada parte del proyecto.

Este proyecto provee una experiencia de aprendizaje integral en el manejo de algoritmos, estructuras de datos y optimización, enfocados en la resolución de problemas reales en el ámbito de la programación y la simulación.

Recuerda subir el código de tu tarea en este repositorio a más tardar el día de la entrega a las 23:59 hrs.

El codigo base de esta tarea es un poco más extraño debido a que se incluye un visualizador para la Parte 3. La estructura de la tarea es la siguiente:

```
src/
-----------------------------------------------------------------------
│   ARCHIVOS DE LA TAREA ( Donde escribirás tu código )               │
-----------------------------------------------------------------------
├── bstmate/
│   ├── main.c
│   ... Otros archivos de la parte 1
├── qsortcars/
│   ├── main.c
│   ... Otros archivos de la parte 2
├── kdtree/
│   ├── main.c
│   ├── simulation.c
│   ├── simulation.h
│   ... Otros archivos de la parte 3
-----------------------------------------------------------------------
│   LIBRERIAS PARA EL VISUALIZADOR ( No es necesario modificarlas )   │
-----------------------------------------------------------------------
│── engine/
│   ├── math/
│   ├── vector.c
│   ├── vector.h
│── visualizer/
│   ├── visualizer.c
│   ├── visualizer.h
│── visualizer_core
│   ├── animating/
│   ├── drawing/
│   ├── main.c
│   ├── window.c
│   ├── window.h
```

## Compilar

```
make
```

## Recompilar

```
make clean && make
```

## Ejecutar

### Para la parte 1:
```
./bstmate input.txt output.txt
```

### Para la parte 2:
```
./qsortcars input.txt output.txt
```

### Para la parte 3:

Para esta parte existe un visualizador de las colisiones para hacer la tarea mas dinamica. Si no lo has instalado revisa la guia:
[Guia de instalacion GTK](https://github.com/IIC2133-PUC/2023-1/blob/master/Gu%C3%ADas/Set%20Up/3.0%20(Extra)%20GTK.md)

```
./kdtree input.txt output.txt
```

En caso de problemas con el visualizador puedes utilizar

```
./kdtree input.txt output.txt --novis
```