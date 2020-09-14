/*
 * Author:      Asif Ahmed
 * Version:     0.2
 * Site:        quickgrid.blogspot.com
 * Description: kshapejs is a simple javascript library based on konvajs.
 *              It allow creating some basic shapes not defined in konva
 *              library.
 */

(function(window){
    'use strict';
    function define_library(){
        var kshapejs = {};

        // Takes kx,ky coordinates of triangle which is left top most point and the triangle size, stroke width
        kshapejs.drawTriangle = function(kx, ky, ktrianglesize, kstrokeWidth){

            var triangle = [ kx, ky, kx, ky + ktrianglesize, kx + ktrianglesize, ky + ktrianglesize / 2 ];

            var poly = new Konva.Line({
              points: triangle,
              stroke: 'black',
              strokeWidth: kstrokeWidth,
              closed : true
            });

            return poly;
        }


        // Takes kx,ky coordinates of line, width, orientation, line length, stroke size
        kshapejs.drawLine = function(kx, ky, korientation, klineLength, kstrokeWidth ){

          var kendX = kx;
          var kendY = ky;

          if( korientation === 'h' ){
            kendX = kx + klineLength;
          }
          if( korientation === 'v' ){
            kendY = ky + klineLength;
          }

          var line = new Konva.Line({
            points: [kx, ky, kendX, kendY],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });

          return line;

        }


        /*
         * TODO: Create resistor points with loop & create size based on single variable instead of two
         */

        // Takes five parameters x,y coordinates, width, height, stroke width
        kshapejs.drawResistor = function(kx, ky, kw, kstrokeWidth, kresistorValue){

          var group = new Konva.Group({
              draggable: true,
              x: 50, y: 50
          });

          var line = new Konva.Line({
            points: [kx, ky, kx + kw, ky, kx + 2 * kw, ky - kw, kx + 3 * kw, ky + kw, kx + 4 * kw, ky - kw, kx + 5 * kw, ky + kw, kx + 6 * kw, ky, kx + 8 * kw, ky],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });


          var tmp = kresistorValue.toString();
          var resistorValue = new Konva.Text({
            x: (kx / 2 + kx + kw + 7 * kw) / 2,
            y: (ky / 2 - ky - kw + 5 * kw) / 2,
            //y: ky -55,
            text: tmp,
            fontSize: 20,
            fontFamily: 'Calibri',
            fill: 'green'
          });


          group.add(line);
          group.add(resistorValue);

          return group;

        }



        //
        kshapejs.drawDcVoltageSource = function(kx, ky, klineLength, kstrokeWidth){
          var group = new Konva.Group({
              draggable: true,
              x: 100, y: 100
          });

          var line1 = new Konva.Line({
            points: [kx, ky, kx + klineLength, ky],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });

          var line2 = new Konva.Line({
            points: [ kx + (kx + klineLength) / 4, ky + klineLength / 5 , kx + klineLength  - (kx + klineLength) / 4 , ky + klineLength / 5 ],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });

          var pinTop = new Konva.Line({
            points: [(kx + kx + klineLength) / 2, ky, (kx + kx + klineLength) / 2, ky - klineLength / 3],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });

          var pinBottom = new Konva.Line({
            points: [(kx + kx + klineLength) / 2, ky + klineLength / 5 , (kx + kx + klineLength) / 2, ky + klineLength / 5 + klineLength / 3],
            stroke: 'black',
            strokeWidth: kstrokeWidth,
            lineCap: 'round',
            lineJoin: 'round'
          });


          group.add(line1);
          group.add(line2);
          group.add(pinTop);
          group.add(pinBottom);


          return group;
        }




        return kshapejs;
    }


    //define globally if it doesn't already exist
    if(typeof(kshapejs) === 'undefined'){
        window.kshapejs = define_library();
    }
    else{
        console.log("kshapejs already defined.");
    }
})(window);
