<template>
  <div id="app">
    <!-- <img src="./assets/logo.png"> -->
    <img src="http://www.xpuca.top/IMG_0116.JPG" style="width: 300px; height: 200px">
    <h1 class="myclass1">ahoj</h1>
    <hr>
    <router-link to="/"><button class="btn btn-warning">Home</button></router-link>
    <router-link to="SaySomething"><button class="btn btn-primary">SaySomething</button></router-link>
    <router-link to="News"><button class="btn btn-success">News</button></router-link>
    <router-link to="AboutMe"><button class="btn btn-danger">AboutMe</button></router-link>
    <hr>
    <router-view/>
  </div>
</template>

<script>
import "./assets/mystyle.css"
export default {
  name: "App"
};
</script>

<style>
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
