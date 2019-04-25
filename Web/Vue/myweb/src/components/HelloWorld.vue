<template>
    <div class="hello">
        <pre>{{content}}</pre>
    </div>
</template>

<script>
    export default {
        name: "HelloWorld",
        data() {
            return {
                content: "Hello world Page!",
            };
        },
    };
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
