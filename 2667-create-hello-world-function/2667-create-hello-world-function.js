/**
 * @return {Function}
 */
var createHelloWorld = function() { 
   
    return function() {
        // console.log("Hello World");
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */