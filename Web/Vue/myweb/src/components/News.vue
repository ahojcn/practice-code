<template>
  <div>
      {{content}}
  </div>
</template>

<script>
export default {
  name: "HelloWorld",
  data() {
    return {
      content: {}
    };
  },
  mounted() {
    this.axios.post("http://api.komavideo.com/news/list").then(body => {
      this.content = body.data;
    });
  }
};
</script>

<style scope>
</style>