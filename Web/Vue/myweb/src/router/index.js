import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import SaySomething from '@/components/SaySomething'
import News from '@/components/News'
import AboutMe from '@/components/AboutMe'

Vue.use(Router)

export default new Router({
    routes: [
        {
            path: '/',
            name: 'HelloWorld',
            component: HelloWorld
        },
        {
            path: '/saysomething',
            name: 'SaySomething',
            component: SaySomething
        },
        {
            path: '/news',
            name: 'News',
            component: News
        },
        {
            path: '/aboutme',
            name: 'AboutMe',
            component: AboutMe
        }
    ]
})
