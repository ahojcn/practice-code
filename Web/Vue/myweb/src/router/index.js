import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import SaySomething from '@/components/SaySomething'
import News from '@/components/News'
import AboutMe from '@/components/AboutMe'
import Player from '@/components/Player'
import PlayerProfile from '@/components/Player/Profile'
import PlayerStats from '@/components/Player/Stats'
import SettingDetail from '@/components/Setting/Detail'
import SettingHeader from '@/components/Setting/Header'
import SettingSidebar from '@/components/Setting/SideBar'

Vue.use(Router);

export default new Router({
    routes: [
        {
            path: '/',
            name: 'HelloWorld',
            components: {
                myHeader: SettingHeader,
                mySidebar: SettingSidebar,
                myDetail: SettingDetail
            }
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
        },
        {
            path: '/player/:uid',
            name: 'Player',
            component: Player,
            children: [
                {
                    path: 'profile',
                    component: PlayerProfile,
                },
                {
                    path: 'stats',
                    component: PlayerStats,
                },
            ]
        },
    ]
})
