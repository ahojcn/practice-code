<template>
    <div id="app">
        <!-- <img src="./assets/logo.png"> -->
        <img alt="doge" src="http://www.xpuca.top/IMG_0116.JPG" style="width: 300px; height: 200px">
        <h1 class="myclass1">ahoj</h1>
        <hr>
        <router-link to="/">
            <button class="btn btn-warning">Home</button>
        </router-link>
        <router-link to="SaySomething">
            <button class="btn btn-primary">SaySomething</button>
        </router-link>
        <router-link to="News">
            <button class="btn btn-success">News</button>
        </router-link>
        <router-link to="AboutMe">
            <button class="btn btn-danger">AboutMe</button>
        </router-link>
        <hr>
        <router-link to="/player/1">库里</router-link>
        <router-link to="/player/2">科比</router-link>
        <hr>
        <h3>路由也编程</h3>
        <button @click="btnClick(1)" class="btn btn-light">库里</button>
        <button @click="btnClick(2)" class="btn btn-dark">科比</button>
        <hr>
        <router-link :to="{name: 'Player', params: {uid: 1}}">
            <button class="btn btn-outline-primary">库里</button>
        </router-link>
        <router-link :to="{name: 'Player', params: {uid: 2}}">
            <button class="btn btn-outline-primary">科比</button>
        </router-link>
        <router-view/>
        <hr>
        <table width="100%">
            <tr>
                <td colspan="2" style="background-color:darkgoldenrod">
                    <router-view name="myHeader"></router-view>
                </td>
            </tr>
            <tr>
                <td width="20%" style="background-color:thistle">
                    <router-view name="mySidebar"></router-view>
                </td>
                <td width="80%" style="background-color:aquamarine">
                    <router-view name="myDetail"></router-view>
                </td>
            </tr>
        </table>
    </div>
</template>

<script>
    import "./assets/mystyle.css"

    export default {
        name: "App",
        methods: {
            btnClick(uid) {
                this.$router.push({path: `/player/${uid}`});
                // this.$router.push({path: `/player/${uid}/stats`});
                // this.$router.push({name: 'Player', params: {uid: uid}});

                // this.$router.push({path: '/player', query: {uid: uid}});    // url-get参数写法

                // this.$router.go(-1);     // 浏览器的历史前进后退（1，前进。-1，后退。）
            }
        }
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
