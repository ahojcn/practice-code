<template>
    <div>
        <h1>{{msg}}</h1>
    </div>
</template>

<script>
export default {
    name: 'SaySomething',
    data() {
        return {
            msg: "SaySomething Page!",
        }
    },
}
</script>

<style scoped>
h1 {
    font-weight: normal;
    color: red;
}
</style>