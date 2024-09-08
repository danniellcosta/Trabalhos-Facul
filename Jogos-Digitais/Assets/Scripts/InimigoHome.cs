using System.Collections;
using UnityEngine;

public class InimigoHome : InimigoComportamento
{
    public Transform insideTransform;
    public Transform outsideTransform;

    private void OnEnable()
    {
        StopAllCoroutines();
    }

    private void OnDisable()
    {
        if (this.gameObject.activeSelf)
        {
            StartCoroutine(ExitTransition());
        }

    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (this.enabled && collision.gameObject.layer == LayerMask.NameToLayer("Obstaculos"))
        {
            this.inimigo.movimento.SetDirecao(-this.inimigo.movimento.direcao);
        }
    }

    private IEnumerator ExitTransition()
    {
        this.inimigo.movimento.SetDirecao(Vector2.up, true);
        this.inimigo.movimento.rgdb2D.isKinematic = true;
        this.inimigo.movimento.enabled = false;

        Vector3 posicao = this.transform.position;

        float duracao = 0.5f;
        float elapsed = 0.0f;

        while (elapsed < duracao)
        {
            Vector3 novaPosicao = Vector3.Lerp(posicao, this.insideTransform.position, elapsed / duracao);
            novaPosicao.z = posicao.z;
            this.inimigo.transform.position = novaPosicao;
            elapsed += Time.deltaTime;
            yield return null;
        }

        elapsed = 0.0f;

        while (elapsed < duracao)
        {
            Vector3 novaPosicao = Vector3.Lerp(this.insideTransform.position, this.outsideTransform.position, elapsed / duracao);
            novaPosicao.z = posicao.z;
            this.inimigo.transform.position = novaPosicao;
            elapsed += Time.deltaTime;
            yield return null;
        }


        this.inimigo.movimento.SetDirecao(new Vector2(Random.value < 0.5f ? -1.0f : 1.0f, 0.0f), true);
        this.inimigo.movimento.rgdb2D.isKinematic = false;
        this.inimigo.movimento.enabled = true;
    }
}
